import tkinter as tk
from tkinter import ttk
# This computes the Celsius temperature from the Fahrenheit.
def findcel():
       famt = ftmp.get()
       if famt == '':                      #not double quote, 2 single quotes
             cent.configure(text='')
       else:
             famt = float(famt)
       camt = (famt - 32) / 1.8
# A method (configure) applied to an object (cent) that is converted to a string (str(camt)).
       cent.configure(text=str(camt))
# This grids the widget object where indicated, then returns it.
def mkgrid(r, c, w):
       w.grid(row=r, column=c, sticky='news')
       return w
root = tk.Tk()
root.title('Temp Conversion')  
# The rest hooks the temps into the grid graphics manager widgets.
flab = mkgrid(0, 0, ttk.Label(root, text="Fahrenheit Temperature",
                         anchor='e'))
clab = mkgrid(1, 0, ttk.Label(root, text="Celsius Temperature",
                         anchor='e'))
ftmp = mkgrid(0, 1, ttk.Entry(root))
cent = mkgrid(1, 1, ttk.Label(root, text="", relief='sunken',
                         anchor='w'))
elab = mkgrid(0, 2, ttk.Label(root, text=''))
fbut = mkgrid(1, 2, ttk.Button(root, text="Compute Celsius",
                           command=findcel))
# Starts the root main event loop
root.mainloop()
