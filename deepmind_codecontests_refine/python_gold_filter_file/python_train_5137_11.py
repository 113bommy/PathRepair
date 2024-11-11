from sys import stdin,stdout
inpt = lambda: stdin.readline().strip()
prnt = lambda x: stdout.write(str(x))
def no_of_div(s):
    n = len(s)
    divisors = [s]
    for i in range(2,n+1):
        d = n//i
        if d*i==n and s[0:d]*i==s:
            divisors.append(s[0:d])
    return divisors
s1 = inpt()
s2 = inpt()
prnt(len(set(no_of_div(s1)).intersection(no_of_div(s2))))