def Music2(T,S,q):
    intersect = S*q
    count = 1
    while intersect < T:
        count += 1
        intersect += S*q**count
    return count
s = input()
s = s.split()
print(Music2(int(s[0]),int(s[1]),int(s[2])))