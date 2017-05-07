from tkinter import *
from tkinter.messagebox import showinfo
from functools import partial
from RotaSquare.GUI import UserInterface


class TkinterUserInterface(UserInterface):
    def __init__(self, g):
        UserInterface.__init__(self, g)

        # Window initialisation

        self.window = Tk()
        self.window.title = "RotaSquare"
        #self.window.geometry("500x500")
        self.window.resizable(False, False)

        # Menu configuration

        def alert():
            showinfo("alerte", "Bravo!")

        self.menuBar = Menu(self.window)

        menu_file = Menu(self.menuBar, tearoff=0)
        menu_file.add_command(label="Créer", command=alert)
        menu_file.add_command(label="Editer", command=alert)
        menu_file.add_separator()
        menu_file.add_command(label="Quitter", command=self.window.quit)

        menu_edit = Menu(self.menuBar, tearoff=0)
        menu_edit.add_command(label="Couper", command=alert)
        menu_edit.add_command(label="Copier", command=alert)
        menu_edit.add_command(label="Coller", command=alert)

        menu_propos = Menu(self.menuBar, tearoff=0)
        menu_propos.add_command(label="A propos", command=alert)

        self.menuBar.add_cascade(label="Fichier", menu=menu_file)
        self.menuBar.add_cascade(label="Editer", menu=menu_edit)
        self.menuBar.add_cascade(label="Aide", menu=menu_propos)

        # Window components

        self.window.config(menu=self.menuBar)
        self.title_label = Label(self.window, text="RotaSquare", background='red', anchor=CENTER)
        self.canvas = Canvas(self.window, background="white")

        self.left_button = Button(self.window, text="<-")
        self.right_button = Button(self.window, text="->")
        self.accept_button = Button(self.window, text="Accepter")

        self.label_player1 = Label(self.window, text="Joueur 1")
        self.label_player2 = Label(self.window, text="Joueur 2")

        # Provisoire
        self.text = StringVar(self.window)
        self.text = '1'
        self.entry = Entry(self.window, textvariable=self.text)

    def display_init(self):
        self.title_label.grid(row=0, column=3, sticky="ns")
        self.canvas.grid(row=2, column=3)
        self.label_player1.grid(row=2, column=0)
        self.label_player2.grid(row=2, column=5)
        self.left_button.grid(row=3, column=1)
        self.right_button.grid(row=3, column=4)
        self.accept_button.grid(row=6, column=3)
        self.entry.grid(row=5, column=3)

    def display(self):
        self.window.mainloop()

    def display_rota(self):
        pass

    def display_win(self):
        pass

    @property
    def input_turn(self):
        return 1
