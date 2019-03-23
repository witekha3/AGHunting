import socket

host = ('127.0.0.1', 35000)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(host)

msg = bytearray()

msg.append(125)
msg.append(255)
msg.append(255)
msg.append(255)
msg.append(255)
msg.append(255)
msg.append(255)

s.send(msg, len(msg))




