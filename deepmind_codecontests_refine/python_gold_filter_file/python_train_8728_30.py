import sys
from itertools import accumulate
def input(): return sys.stdin.readline().strip()

def main():
    X, Y = map(int, input().split())
    """
    必勝法は「相手に山の差が１になるようにターンを渡すこと」
    そしたら相手がどんな操作をしてきても再び山の差を１にできるので、
    最終的には(0, 0), (0, 1), (1, 0)のどれかの状態を相手にわたすことになる。

    これどうやったら気づけるの？定常状態があるのがこの手の問題の定石？
    """
    if abs(X - Y) <= 1:
        print("Brown")
    else:
        print("Alice")
    

if __name__ == "__main__":
    main()
