def main():
    test=int(input())
    i=0
    while i<test:
        l,r=map(int,input().split(" "))
        rem=max_mod(l,r)
        print(rem)
        i+=1

def max_mod(min,max):
    if max//2>=min:
        max_rem=(max//2)%(max-1)
    else:
        max_rem=(max-min)
    return max_rem

if __name__=="__main__":
    main()