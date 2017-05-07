from tkinter import *
from tkinter.messagebox import showinfo
from functools import partial

from GUI import UserInterface

class TkinterUserInterface(UserInterface):

    def __init__(self, g):
        UserInterface.__init__(self, g)

        # Attributes

        self.selected_column = 0

        # Window initialisation

        self.window = Tk()
        self.window.title = "RotaSquare"
        #self.window.geometry("500x500")
        self.window.resizable(False, False)

        # Menu configuration

        def alert():
            showinfo("Info", "RotaSquare!\nVersion 1.5")

        self.menuBar = Menu(self.window)

        menu_file = Menu(self.menuBar, tearoff=0)
        menu_file.add_command(label="New Game", command=alert)
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
            if (self.selected_column > 0):
                self.selected_column -= 1
                self.display()

        def click_right_button():
            if (self.selected_column < 7):
                self.selected_column += 1
                self.display()

        def click_accept_button():
            self.game.resume_main(self.selected_column)

        self.left_button = Button(self.window, text="<-", command=click_left_button)
        self.right_button = Button(self.window, text="->", command=click_right_button)
        self.accept_button = Button(self.window, text="Accept", command=click_accept_button)

        self.label_player1 = Label(self.window, text="Joueur 1")
        self.label_player2 = Label(self.window, text="Joueur 2")

        # Provisoire
        self.text = StringVar(self.window)
        self.text = '1'
        self.entry = Entry(self.window, textvariable=self.text)

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
        self.label_player1.grid(row=2, column=0)
        self.label_player2.grid(row=2, column=5)
        self.left_button.grid(row=3, column=1)
        self.right_button.grid(row=3, column=4)
        self.accept_button.grid(row=6, column=3)
        self.entry.grid(row=5, column=3)
        self.display()

    def display(self):
        self.tableau_to_canvas(self.game.board.tab, self.selected_column)

    def display_rota_resume(self):
        self.title_label.config(text="RotaSquare", background='white')
        self.display()

    def display_rota(self):
        self.title_label.config(text="ROTATION!", background='yellow')
        self.window.after(1000, self.display_rota_resume)

    def display_win(self):
        self.display()
        if (self.game.win == 1):
            showinfo("Info", "PLAYER 1 WINS!")
        elif (self.game.win == 2):
            showinfo("Info", "PLAYER 2 WINS!")
        elif (self.game.win == 3):
            showinfo("Info", "DRAW!")
        self.window.destroy()

    def wait_input(self):
        self.window.mainloop()
