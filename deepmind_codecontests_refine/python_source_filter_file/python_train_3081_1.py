# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

if __name__ == '__main__':
    rows = []
    count = 0
    for _ in range(8):
        rows.append(input())
        if rows[-1] == "B"*8:
            count += 1
    # now count columns
    if count == 8:
        print(8)
    else:
        for i in range(8):
            if [rows[j][i] for j in range(8)] == ["B"*8]:
                count += 1
        print(count)
