


def biton(num, idx):
    return (1<<idx & num) > 0



def main():

    n = int(input())

    for i in range(n):
        a,b,c = [int(x) for x in input().split()]
        result = 0
        for i in range(12):
            if biton(a, i) and biton(b, i):
                 if c%3 != 2:
                     result += 2**i

            elif biton(a, i) and not biton(b, i):
                 if c%3 != 1:
                     result += 2**i    

            elif not biton(a, i) and biton(b, i):
                 if c%3 != 0:
                     result += 2**i
        
        print(result)



if __name__ == '__main__':
    main()