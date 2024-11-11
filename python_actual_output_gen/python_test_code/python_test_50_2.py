def get_longest(s):
    c = 1
    m = 0
    for i in range(1,len(s)):
        if s[i]=="L":
            c+=1
        else:
            if c >= m:
                m = c
            c = 0
    if c > m:
        m = c
    return m


t = int(input())
while t:
    z = input()
    if "R" not in z:
        print(len(z)+ 1)
    elif "L" not in z:
        print(1)
    else:
        r = get_longest(z)
        print(r+1)
    t-=1