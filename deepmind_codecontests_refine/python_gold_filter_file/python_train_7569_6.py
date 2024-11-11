def rev(string): 
    string = "".join(reversed(string)) 
    return string 

def algo(s, n):
    for x in range(2, n + 1):#x = 2
        if n % x == 0:# true
            s = rev(s[0:x]) + s[x:n]
            
            
    return s

n = int(input())
t = input()
ans = algo(t, n)
print(ans)
        