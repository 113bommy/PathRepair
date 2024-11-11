for _ in range(int(input())):
        n = int(input())
        s = input()
        d = [] 
        for i in range(n):
            if s[i] == 'A':
                d.append(i)
        d.append(n)
        diff = 0
        for i in range(len(d)-1):
            diff = max(diff,d[i+1]-d[i]-1)
        print(diff)
     

