# import inbuilt standard input output
from sys import stdin, stdout
def main():
    # input via readline method
    # n = stdin.readline()
    for _ in range(int(stdin.readline())):
# array input similar method
        arr = [int(x) for x in stdin.readline().split()]
        pairs=arr[0]+arr[1]+arr[2]-3
        if(pairs>=arr[3] and (pairs+3-max(arr[0],arr[1],arr[2])>=(max(arr[0],arr[1],arr[2])-1))):
            stdout.write('YES\n')
        else:
            stdout.write('NO\n')

    # stdout.write(str(summation))

if __name__ == "__main__":
    main()   