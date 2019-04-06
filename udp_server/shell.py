#!/usr/bin/python

import socket
import sys

def usage():
    print("./shell.py <ip> <port>")

def msg(msg):
    print("$> " + str(msg))

class Controller:
    def start(self): 
        if (len(sys.argv) < 3):
            return usage()
        
        self.ip   = sys.argv[1]
        self.port = int(sys.argv[2])
        
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        
        msg("Connecting to server on %s:%d" % (self.ip, self.port))

        try:
            self.sock.connect((self.ip, self.port))
        except Exception as e:
            print("$> Error while connecting to server: " + str(e))
            return
        
        msg("Connection successfull!")
        msg("Shell is ready.\n\n")
       
        self.is_running = True

        while self.is_running:
            self.handle_input()
    
        self.sock.close()

    def handle_input(self):
        cmd = raw_input("$> ")
        
        if (cmd.startswith("shutdown")):
            self.shutdown()
        elif (cmd.startswith("disconnect")):
            self.disconnect()
        elif (cmd.startswith("help")):
            self.help()
        else:
            print("\nUnknown command, type help for command list.\n")
              
    # cmd handlers
    def shutdown(self):
        self.sock.send("shutdown".encode('utf-8'))
        self.is_running = False

    def disconnect(self):
        self.is_running = False

    def help(self):
        print("\nAllowed commands: help, disconnect, shutdown\n")

# -- start point --
if __name__ == '__main__':
    c = Controller()
    c.start()

