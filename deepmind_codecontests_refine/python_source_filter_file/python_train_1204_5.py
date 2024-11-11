def function1(n,s):
    if n==1:
        return 1
    pokemonj=0
    pokecage=[0 for i in range(100001)]
    for i in range(n):
        pokecage[s[i]]+=1
    maxyincage=pokecage[1]
    a = [i for i in range(100001)]
    a[1] = 0

    i = 2

    while i <= 100000:
        if a[i] != 0:

            pokemonj=0
            for j in range(i, 100001, i):
                a[j] = 0
                pokemonj+=pokecage[j]
            if pokemonj>maxyincage:
                maxyincage=pokemonj

        i += 1

    return(maxyincage)



def main():
    n=int(input())
    s=list(map(int,input().split()))
    print(function1(n,s))
if __name__=='__main__':
    main()


