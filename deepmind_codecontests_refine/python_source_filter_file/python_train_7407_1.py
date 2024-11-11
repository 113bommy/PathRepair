def main():
    n = int(input())
    e = [int(input()) for i in range(n)]
    r = 0
    for j in e:
        c = 1
        while j>0:
            j = e[j-1]
            c+=1
        r = max(c,r)
    return r
    
main()