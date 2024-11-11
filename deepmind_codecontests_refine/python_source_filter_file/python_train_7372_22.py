(d, g), *s = [list(map(int, i.split())) for i in open(0)]
def c(i,t,l):
    if i==d:
        if t>=g:
            return sum(l)
        else:
            m=d-l[::-1].index(0)
            e = -(t - g) // (m * 100)
            if e < s[m-1][0]:
                return sum(l)+e
            else:
                return 10**3
    return min(c(i+1,t,l+[0]),c(i+1,t+s[i][0]*-~i*100+s[i][1],l+[s[i][0]]))
print(c(0,0,[]))