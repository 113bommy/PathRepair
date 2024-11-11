s = input()
t = input()
if s[0] == "0" and s[3] == "0":
    h1 = int(s[1])
    m1 = int(s[4])
elif s[0] == "0" and s[3] != "0":
    h1 = int(s[1])
    m1 = int(s[3:])
elif s[0] != "0" and s[3] == "0":
    h1 = int(s[:2])
    m1 = int(s[4])
elif s[0] != "0" and s[3] != "0":
    h1 = int(s[:1])
    m1 = int(s[3:])
if t[0] == "0" and t[3] == "0":
    h2 = int(t[1])
    m2 = int(t[4])
elif t[0] == "0" and t[3] != "0":
    h2 = int(t[1])
    m2 = int(t[3:])
elif t[0] != "0" and t[3] == "0":
    h2 = int(t[:2])
    m2 = int(t[4])
elif t[0] != "0" and t[3] != "0":
    h2 = int(t[:1])
    m2 = int(t[3:])
if m1 < m2:
    h3 = ((h1 + 23) - h2) % 24
    m3 = (m1 + 60) - m2
elif m1 >= m2:
    h3 = ((h1 + 24) - h2) % 24
    m3 = (m1 - m2)
if h3 > 9 and m3 > 9:
    print(str(h3) + ":" + str(m3))
elif h3 > 9 and m3 <= 9:
    print(str(h3) + ":" + "0" + str(m3))
elif h3 <= 9 and m3 > 9:
    print("0" + str(h3) + ":" + str(m3))
elif h3 <= 9 and m3 <= 9:
    print("0" + str(h3) + ":" + "0" + str(m3))




