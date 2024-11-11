#!/usr/bin/python3
s = input()
MOD_N = 1 * 10 ** 9 + 7
result = 0
def add(a, b):
    global result
    global MOD_N
    result += result * a * b + a
    result %= MOD_N

c_pos = 0
while c_pos < len(s) and s[c_pos] != 'a':
    c_pos += 1

#s[c_pos] == 'a' or no 'a' in 's'

while c_pos < len(s):
    if s[c_pos] == 'b':
        break
    elif s[c_pos] == 'a':
        result += 1
    c_pos += 1

if c_pos == len(s):
    print ("{}".format(result))
    exit(0)

last = 'b'
last_b = 0
last_a = 0
s_a = []
s_b = []

c_pos += 1
while c_pos < len(s):
    c = s[c_pos]
    if c not in 'ab':
        c_pos += 1
        continue
    if c == last == 'a':
        last_a += 1
    elif c == last == 'b':
        last_b += 1
    elif c == 'a':
        last_a = 1
        last = 'a'
    else: # c == 'b'
        add(last_a, last_b)
        last_a = 0
        last_b = 1
        last = 'b'
    c_pos += 1

add(last_a, last_b)
print ("{}".format(result))
