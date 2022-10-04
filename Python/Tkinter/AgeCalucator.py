from tkinter import *
import datetime
import tkinter.messagebox as tmsg
def take():
    name = name_value.get()
    year = year_value.get()
    month = month_value.get()
    date = date_value.get()

    cur = datetime.datetime.now()
    cur_year = cur.year
    cur_month = cur.month
    cur_date = cur.day

    your_age = cur_year - year - 1
    your_month = abs(abs(cur_month - month) - 11)
    list_31 = (1,3,5,7,8,10,12)
    list_30 = (4,6,9,11)
    if month in list_31:
        your_day = abs(abs(cur_date - date) - 31)
    elif month in list_30:
        your_day = abs(abs(cur_date - date) - 30)
    elif month == 2:
        if year%4==0 and year%100!=0 or year%400==0:
            your_day = abs(abs(cur_date - date) - 29)
        else:
            your_day = abs(abs(cur_date - date) - 28)
    else:
        tmsg.showerror("Error", "Month should be between 1-12")
    if date > 31 or date < 1:
        tmsg.showerror("Error", "Date should be between 1-31")

    if year>=0 and date>0 and date<32 and month>0 and month<13:
        tmsg.showinfo(f"Hello {name}", f"You are {your_age} years {your_month} months {your_day} days young! ")

def current():
    tmsg.showinfo("Today's Date", datetime.datetime.today())

root = Tk()
root.geometry("700x600")
root.title("Age Calculator")
root.minsize(700, 600)
root.maxsize(700, 600)
root.configure(bg="Powder Blue")

lb = Label(text="Age Calculator", padx=20, pady=20, font=" comicsansms 36 bold", bg="Powder Blue", fg="Red")
lb.grid()
lb1 = Label(text="Enter your age below:", padx=20, pady=20, font=" comicsansms 18 bold", bg="Powder Blue", fg="Navy Blue")
lb1.grid()

name_lb = Label(text="Enter your Name:", padx=20, pady=20, font=" comicsansms 13 bold", bg="Powder Blue", fg="Navy Blue")
name_lb.grid(row=3, column=0)

date_lb = Label(text="Enter the date:", padx=20, pady=20, font=" comicsansms 13 bold", bg="Powder Blue", fg="Navy Blue")
date_lb.grid(row=4, column=0)

month_lb = Label(text="Enter the month:", padx=20, pady=20, font=" comicsansms 13 bold", bg="Powder Blue", fg="Navy Blue")
month_lb.grid(row=5, column=0)

year_lb = Label(text="Enter the year of birth:", padx=20, pady=20, font=" comicsansms 13 bold", bg="Powder Blue", fg="Navy Blue")
year_lb.grid(row=6, column=0)

name_value = StringVar()
name_value.set('Anonymous')
year_value = IntVar()
month_value = IntVar()
date_value = IntVar()

name_entry = Entry(root, textvariable= name_value)
name_entry.grid(row=3,column=1)
date_entry = Entry(root, textvariable= date_value)
date_entry.grid(row=4,column=1)
month_entry = Entry(root, textvariable= month_value)
month_entry.grid(row=5,column=1)
year_entry = Entry(root, textvariable= year_value)
year_entry.grid(row=6,column=1)

l = Label(bg="Powder blue")         #empty label for extra space
l.grid(row=7, column=1)

fr = Frame(root, bg="Powder Blue")
fr.grid(row=8, column=1)
submit_b = Button(fr, text="Calculate", font = "18", bg="Light Grey", fg="Navy Blue", relief=RAISED, width="15", command=take)
submit_b.grid(row=8, column=1)

fr = Frame(root, bg="Powder Blue")
fr.grid(row=8, column=0)
current_button = Button(fr, text="Show Current Date", font = "18", bg="Light Grey", fg="Navy Blue", relief=RAISED, width="15", command=current)
current_button.grid(row=8, column=0)

root.mainloop()
