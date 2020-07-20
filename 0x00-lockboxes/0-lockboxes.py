#!/usr/bin/python3
"""Lockboxes exercise interview"""
from itertools import dropwhile


def canUnlockAll(boxes):
    """Check boxes"""
    keys = {0}
    rangeOfBoxes = range(len(boxes))

    while True:
        notFound = set()

        for i in rangeOfBoxes:
            if i in keys:
                for key in dropwhile(lambda k: k in keys, boxes[i]):
                    keys.add(key)

            else:
                notFound.add(i)

        if rangeOfBoxes == notFound:
            return False

        if not notFound:
            return True

        rangeOfBoxes = notFound
