def main():
    b,k = map(int,input().split())
    a = list(map(int,input().split()))
    even = 0
    odd = 0
    for i in a:
        if i%2 == 0:
            even += 1
        else:
            odd += 1
            
    if k%2 == 0:
        if a[-1]%2 == 0:
            print ('even')
        else:
            print ('odd')
    else:
        if odd%2 == 0:
            print  ('even')
        else:
            print ('odd')
            
main()
