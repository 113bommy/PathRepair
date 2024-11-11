n = input()

s_o = -1
s_c = -1

for i in range(len(n)):
    if n[i] == '[':
        s_o = i
        break

for i in range(len(n)-1, -1, -1):
    if n[i] == ']':
        s_c = i
        break
# print(s_o, s_c)
st = -1
fin = -1
a = 0
f = True
try:
    if (s_o >= s_c or s_c - s_o < 2) or (s_o == -1 or s_c == -1):
        f = False

    else:

        for i in range(s_o, s_c):
            if n[i] == ':':
                st = i
                break
        for i in range(s_c, s_o, -1):
            if n[i] == ':':
                if i > st:
                    fin = i
                else:
                    f = False
                break
        for i in range(st, fin):
            if n[i] == '|':
                a += 1
    # print(st, fin)
    if st == -1 or fin == -1:
        f = False
except IndexError:
    f = False

if f:
    print(a+4)
else:
    print(-1)