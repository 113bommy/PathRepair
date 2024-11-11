from sys import stdin
def main():
    n = [int(x) for x in stdin.readline().strip().split()]
    x = stdin.readline().strip()
    band = True
    for i in x:
        a = x.count(i)
        if n[1]%a != 0:
            band = False
    if band == False:
        print("NO")
    else:
        print("YES")
main()
