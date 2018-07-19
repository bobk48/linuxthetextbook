from wsgiref.simple_server import make_server
 
def app(environ, start_response):
    start_response('200 OK', [('Content-Type','text/html')])
    yield b"<h1>Linux: The Textbook</h1>"
 
server = make_server('127.0.0.1', 8090, app)
server.serve_forever()
