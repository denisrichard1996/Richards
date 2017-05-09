from tkinter import *
from tkinter.messagebox import showinfo
from functools import partial

from GUI import UserInterface

class TkinterUserInterface(UserInterface):

    def __init__(self, g):
        UserInterface.__init__(self, g)

        # Attributes

        self.selected_column = 0
        self.blocked = False

        # Window initialisation

        self.window = Tk()
        self.window.title = "RotaSquare"
        #self.window.geometry("500x500")
        self.window.resizable(False, False)

        # Menu configuration

        def alert():
            showinfo("Info", "RotaSquare!\nVersion 2.0")

        def click_new_game():
            self.game.reset()
            self.game.main()

        self.menuBar = Menu(self.window)

        menu_file = Menu(self.menuBar, tearoff=0)
        menu_file.add_command(label="New Game", command=click_new_game)
        menu_file.add_separator()
        menu_file.add_command(label="Quitter", command=self.window.destroy)

        menu_propos = Menu(self.menuBar, tearoff=0)
        menu_propos.add_command(label="A propos", command=alert)

        self.menuBar.add_cascade(label="Fichier", menu=menu_file)
        self.menuBar.add_cascade(label="Aide", menu=menu_propos)

        # Window components

        self.window.config(menu=self.menuBar)
        self.title_label = Label(self.window, text="RotaSquare", background='white', anchor=CENTER)
        self.canvas = Canvas(self.window, width=400, height=400, background="white")

        def click_left_button():
            if (not self.blocked and self.selected_column > 0):
                self.selected_column -= 1
                self.display()

        def click_right_button():
            if (not self.blocked and self.selected_column < 7):
                self.selected_column += 1
                self.display()

        def click_accept_button():
            if (not self.blocked and self.game.board.can_add(self.selected_column)):
                self.game.resume_main(self.selected_column)

        self.left_button = Button(self.window, text="<-", command=click_left_button)
        self.right_button = Button(self.window, text="->", command=click_right_button)
        self.accept_button = Button(self.window, text="Accept", command=click_accept_button)

        self.canvas_player1 = Canvas(self.window, width=50, height=50, background="white")
        self.canvas_player2 = Canvas(self.window, width=50, height=50, background="white")

        def mouse_select_column(event):
            if (event.widget == self.canvas):
                new_col = int(event.x/50)
                if (new_col!=8 and new_col!=self.selected_column):
                    self.selected_column = new_col
                    self.tableau_to_canvas(self.game.board.tab, self.selected_column)


        def mouse_click(event):
            if (event.widget == self.canvas):
                self.game.resume_main(self.selected_column)

        self.window.bind("<Motion>", mouse_select_column)
        self.window.bind("<Button-1>", mouse_click)

        # # Provisoire
        # self.text = StringVar(self.window)
        # self.text = '1'
        # self.entry = Entry(self.window, textvariable=self.text)

    def turn_to_canvas(self, turn):
        self.canvas_player1.delete("all")
        self.canvas_player2.delete("all")
        if (turn == 1):
            self.canvas_player1.create_rectangle(0,0,50,50, width=0, fill="yellow")
        else:
            self.canvas_player2.create_rectangle(0,0,50,50, width=0, fill="yellow")
        self.canvas_player1.create_line(5,5,45,45, width=3, fill="red")
        self.canvas_player1.create_line(5,45,45,5, width=3, fill="red")
        self.canvas_player2.create_oval(5,5,45,45, width=3, outline="blue")



    def tableau_to_canvas(self, tab, selected_column):
        self.canvas.delete("all")
        self.canvas.create_rectangle(50*selected_column,0,50*(selected_column+1),400, width=0, fill="lightgrey")
        for i in range(8):
            self.canvas.create_line(0,50*i,400,50*i, width=2, fill="black")
            self.canvas.create_line(50*i,0,50*i,400, width=2, fill="black")
        for x in range(8):
            for y in range(8):
                if (tab[x][y] == 1):
                    self.canvas.create_line(50*y+5, 400-50*x-5, 50*y+45, 400-50*x-45, width=3, fill="red")
                    self.canvas.create_line(50*y+5, 400-50*x-45, 50*y+45, 400-50*x-5, width=3, fill="red")
                if (tab[x][y] == 2):
                    self.canvas.create_oval(50*y+5, 400-50*x-5, 50*y+45, 400-50*x-45, width=3, outline="blue")


    def display_init(self):
        self.title_label.grid(row=0, column=3, sticky="ns")
        self.canvas.grid(row=2, column=3)
        self.canvas_player1.grid(row=2, column=0)
        self.canvas_player2.grid(row=2, column=5)
        self.left_button.grid(row=3, column=1)
        self.right_button.grid(row=3, column=4)
        self.accept_button.grid(row=6, column=3)
        # self.entry.grid(row=5, column=3)
        self.display()

    def display(self):
        self.tableau_to_canvas(self.game.board.tab, self.selected_column)
        self.turn_to_canvas(self.game.player)

    def display_rota_resume(self):
        self.title_label.config(text="RotaSquare", background='white')
        self.blocked = False
        self.display()

    def display_rota(self):
        self.title_label.config(text="ROTATION!", background='yellow')
        self.blocked = True
        self.window.after(500, self.display_rota_resume)

    def display_win(self):
        self.display()
        if (self.game.win == 1):
            showinfo("Info", "PLAYER 1 WINS!")
        elif (self.game.win == 2):
            showinfo("Info", "PLAYER 2 WINS!")
        elif (self.game.win == 3):
            showinfo("Info", "DRAW!")
        self.blocked = True

    def wait_input(self):
        self.window.mainloop()
