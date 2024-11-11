cases = int(input())
string = str(input().rstrip())

real_str = ""
n = 0
m = 1
while n < len(string):
    real_str += string[n]
    #print(n,m)
    n += m
    m += 1
print(real_str)
    

#print(string)
