def main():
    s = input()
    
    a = []
    g = [elem for elem in "aeiou"]
    
    p = []
    
    for i in range(len(s)):
        if (s[i] not in g):
            a.append(s[i])
        else:
            a = []
            
        if len(a) == 3:
            if (a[0] != a[1]) or (a[1] != a[2]):
                a = [ a[2] ]
                p.append(i)
            else:
                a = [ a[1], a[2] ]
            
    for i in range(len(s)):
        if i in p:
            print(" ", end='')
        print(s[i], end='')
    
if __name__ == "__main__":
    main()