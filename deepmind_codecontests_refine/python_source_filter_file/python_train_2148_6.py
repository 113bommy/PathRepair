import sys;

#sys.stdin = open("input.txt", "r");
#sys.stdout = open("output.txt", "w");

def ria():
    return [int(x) for x in input().split()];


n = int(input());
a = ria();
col = [100000000] * 200001;


for i in range(n):
    col[a[i]] = i;

minn = 10000000000;
for i in range(2*n):
    if ( col[i] < minn ):
        minn = col[i];
        ans = i;

print(ans);
    


#sys.stdout.close();
