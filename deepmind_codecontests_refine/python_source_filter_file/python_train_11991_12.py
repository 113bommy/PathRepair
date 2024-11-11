def main():
    s=input()
    t=input()
    def isSub(s,t):
        k=0
        for i in s:
            if i==t[k]:
                k+=1
                if k== len(t) :
                    return True
        return False
    r=0
    for l in range(1,len(s)+1):
        for i in range(len(s)-l):
            new_s=s[:i]+s[i+l:]
            if isSub(new_s,t): r=l ; continue
    print(r)
main()