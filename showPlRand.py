#!/usr/bin/python
from numpy import fromstring
import random, sys

def randMove(s):
    l = list(s)
    en = [i for i, x in enumerate(l) if x == 1]
    move = random.sample(en, 1)
    print int(move[0]-2)

if __name__ == "__main__":
    #pipe in stdout string
    #call randMove on "board"
    instate = sys.stdin.readline()
    state = fromstring(instate, dtype=int, sep=' ');
    randMove(state)
