import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


window = Gtk.Window(title="GTK in Weston")
window.connect("destroy", lambda w: Gtk.main_quit())
window.add(Gtk.Label("GTK in Weston"))
window.show_all()

Gtk.main()
