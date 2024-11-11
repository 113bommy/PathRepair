from sys import stdin, stdout

# Reroute std in/out for testing purposes, remove for submission
# stdin = open("158A_NextRound/input.txt", "r")
# stdout = open("output.txt", "w") 

def main():

    # inp = [a.strip() for a in sys.stdin.readlines()]  #inp is an array of input lines.
    # n, m, a = map(int, stdin.readline().rstrip().split())
    # w = int(input())

    # inp = ["4", "word", "localization", "internationalization", "pneumonoultramicroscopicsilicovolcanoconiosis"]
    # words = [string(x) for x in inp[i].split()]  # use float(x) if dealing with decimal values

    # inp = [a.strip() for a in stdin.readlines()]  #inp is an array of input lines.

    n, k = map(int, stdin.readline().rstrip().split())
    
    ax = list(map(int, stdin.readline().rstrip().split()))

    # print(f'n {n}, k {k}, a {ax}')

    c=0
    v=-1
    for i in range(0, len(ax)):
        if(ax[i] > 0):
            if (i < k or ax[i] == v):
                c= c+1
                v= ax[i]            
            else:
                break
        else:
            break
    print(c)



if __name__ == "__main__":
    main()