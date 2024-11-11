def main():

    no_of_test_cases =int(input())

    l = list(map(int,input().split()))

    print(l)

    for i in range(len(l)):

        if l[i]%2==0:

            l[i]-=1

    print(*l)

if __name__ == "__main__":
    main() 