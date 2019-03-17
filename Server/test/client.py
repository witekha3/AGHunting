import socket

host = ('127.0.0.1', 8080)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(host)
s.send('fdsagsh\ngdfhfdhfffffffffffffffffffffff'.encode('utf-8'))

