from tkinter import *
import tkinter.messagebox as tmsg
import random

point = ""
draws = 0
user_points = 0
comp_points = 0
i = 0

def rock():
    global draws, user_points, comp_points, point, i
    list = ("Rock", "Paper", "Scissors")
    comp_move = random.choice(list)
    move = "Rock"
    if comp_move == "Rock":
        draws += 1
        point = "Its a Draw"
        i += 1
    elif comp_move == "Paper":
        comp_points += 1
        point = "Computer won"
        i += 1
    elif comp_move == "Scissors":
        user_points += 1
        point = "User won"
        i += 1
    lbx.insert(0,"---x---x----x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---")
    lbx.insert(0,f"{point}")
    lbx.insert(0,f"Computer move = {comp_move}")
    lbx.insert(0,f"Your move = {move}")
    lbx.insert(0,f"Game no. {i}")

def paper():
    global draws, user_points, comp_points, point, i
    list = ("Rock", "Paper", "Scissors")
    comp_move = random.choice(list)
    move = "Paper"
    if comp_move == "Paper":
        draws += 1
        point = "Its a Draw"
        i += 1
    elif comp_move == "Scissors":
        comp_points += 1
        point = "Computer won"
        i += 1
    elif comp_move == "Rock":
        user_points += 1
        point = "User won"
        i += 1
    lbx.insert(0,"---x---x----x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---")
    lbx.insert(0,f"{point}")
    lbx.insert(0,f"Computer move = {comp_move}")
    lbx.insert(0,f"Your move = {move}")
    lbx.insert(0,f"Game no. {i}")

def scissors():
    global draws, user_points, comp_points, point, i
    list = ("Rock", "Paper", "Scissors")
    comp_move = random.choice(list)
    move = "Scissors"
    if comp_move == "Scissors":
        draws += 1
        point = "Its a Draw"
        i += 1
    elif comp_move == "Rock":
        comp_points += 1
        point = "Computer won"
        i += 1
    elif comp_move == "Paper":
        user_points += 1
        point = "User won"
        i += 1
    lbx.insert(0,"---x---x----x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---")
    lbx.insert(0,f"{point}")
    lbx.insert(0,f"Computer move = {comp_move}")
    lbx.insert(0,f"Your move = {move}")
    lbx.insert(0,f"Game no. {i}")

def result():
    tmsg.showinfo("Score!", f"No. of wins by User = {user_points}\nNo. of wins by Computer = {comp_points}\nTotal no. of Draws = {draws}")

def collapse():
    if user_points > comp_points:
        win = "\"User wins\""
    elif user_points == comp_points:
        win = "\"It's a draw\""
    else:
        win = "\"Computer wins\""
    tmsg.showinfo("Results!", f"No. of wins by User = {user_points}\nNo. of wins by Computer = {comp_points}\nTotal no. of Draws = {draws}\n{win}")
    exit()

root = Tk()
root.geometry("500x500")
root.minsize(500,500)
root.maxsize(500,500)
root.title("Rock Paper Scissors")
root.configure(bg="grey")

lb = Label(root, text="Rock Paper Scissors Game", font="comicsansms 15 bold", bg="grey",fg="navy blue",padx=20,pady=20)
lb.pack()

fr = Frame(root,bg="grey")
fr.pack()
br = Button(fr,text="Rock", width=10, bg="powder blue",padx=20,pady=10, command=rock)
br.pack(side=LEFT,anchor="nw",padx=10)
bp = Button(fr,text="Paper", width=10, bg="orange",padx=20,pady=10, command=paper)
bp.pack(side=LEFT,anchor="nw",padx=10)
bs = Button(fr,text="Scissors", width=10, bg="light green",padx=20,pady=10, command=scissors)
bs.pack(side=LEFT,anchor="nw",padx=10)

sbar = Scrollbar(root)
sbar.pack(fill=Y, side=RIGHT)
lbx = Listbox(root, yscrollcommand= sbar.set)
lbx.pack(expand=TRUE,fill=BOTH,padx=60,pady=20)
sbar.config(command=lbx.yview)

fr = Frame(root,bg="grey")
fr.pack()
br = Button(fr,text="Check Score", width=10, bg="purple", fg="white", padx=20,pady=10, command=result)
br.pack(side=LEFT, anchor="sw", padx=10,pady=20)
br = Button(fr,text="Exit", width=10, bg="red",padx=20,pady=10, command=collapse)
br.pack(side=LEFT, anchor="sw", padx=10,pady=20)

root.mainloop()