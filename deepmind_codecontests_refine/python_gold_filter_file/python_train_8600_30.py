import sys;

#sys.stdin = open("input.txt", "r");
#sys.stdout = open("output.txt", "w");

def ria():
    return [int(x) for x in input().split()];


q = int(input());
for i in range(q):
    n = int(input());

    if n % 4 == 0:
        print(n // 4);
        continue;
    
    hvar1 = n - 6;
    if hvar1 % 4 == 0 and hvar1 >= 0:
        ans = hvar1 // 4 + 1;
        print(ans);
        continue;
    hvar1 = n - 9;
    if ( hvar1 % 4 == 0  and hvar1 >= 0):
        ans = hvar1 // 4 + 1;
        print(ans);
        continue;
    hvar1 = n - 15;
    if ( hvar1 % 4 == 0  and hvar1 >= 0):
        ans = hvar1 // 4 + 2;
        print(ans);
        continue;

    print(-1);


    

#sys.stdout.close();
