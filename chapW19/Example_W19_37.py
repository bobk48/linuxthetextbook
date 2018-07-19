import tkinter as tk
from tkinter import ttk
from functools import partial

# This is the data generating module, which computes the sum.
def add_it(label_result, n1, n2):
    num1 = (n1.get())
    num2 = (n2.get())
    result = float(num1)+float(num2)
    label_result.config(text="Sum = %f" % result)
    return

# This grids the widget object where indicated, then returns it.
def mkgrid(r, c, w):
       w.grid(row=r, column=c, sticky='news')
       return w

root = tk.Tk()
root.title('Real Number Adder')
# The rest hooks the adder into the grid manager widgets.
add1_lab = mkgrid(0, 0, ttk.Label(root, text="addend 1",
                         anchor='e'))
add2_lab = mkgrid(1, 0, ttk.Label(root, text="addend 2",
                         anchor='e'))
add1= mkgrid(0, 1, ttk.Entry(root))
add2= mkgrid(1, 1, ttk.Entry(root))
spacer = mkgrid(0, 2, ttk.Label(root, text=''))
labelResult = ttk.Label(root)
labelResult.grid(row=7, column=2)
add_it = partial(add_it, labelResult, add1, add2)
add_but = mkgrid(1, 2, ttk.Button(root, text="Add them",
                           command=add_it))
# Starts the root main event loop
root.mainloop()
