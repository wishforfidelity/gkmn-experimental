#!/usr/bin/python
#-*- coding: utf-8 -*-

import time
import sys

class Progress():
    def fWheel(self, wheel, digit):
        return wheel[digit%4]

    def fSpaces(self, tour, digit):
        return "[" + digit * "=" + (tour - digit - 1) * " " + "]"

    def fProgressbar(self, wheel, tour, digit):
        sys.stdout.write("\r%s\t%s " % (self.fSpaces(tour, digit),
                         self.fWheel(wheel, digit)))
        sys.stdout.flush()

    def __init__(self):
        wheel = ("\\", "|", "/", "-")
        tour = 50 - 2

        for digit in range(tour):
            self.fProgressbar(wheel, tour, digit)
            time.sleep(0.04)

        print("\b\bDone.")

if __name__ == '__main__':
    Progress()
