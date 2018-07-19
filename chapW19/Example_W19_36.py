import tkinter
from tkinter import ttk
w = tkinter.Tk()
w.title("Python GUI")
ttk.Label(w,text="My first tkinter gui window").grid(column=0, row=0)
w.mainloop()
