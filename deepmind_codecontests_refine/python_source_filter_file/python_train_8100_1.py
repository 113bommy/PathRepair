'''
辺のコストをmin(Ax, By)とする代わりに、
辺のコストをAxもしくはByの好きな方にしてよいとしたときの最小値を求める

各頂点vについて、
１．Av, Bvともに選ばれる
２．Avのみ選ばれる
３．Bvのみ選ばれる
４．Av, Bvとも選ばれない

すべてタイプ2のときはsum(A), すべてタイプ3のときはsum(B)
それ以外は、タイプ1 = タイプ4 
2...2 4141..4 3...3 1
と構成すればよい
A, Bを合併したリストから小さい順にN個取る
この時に、最初のN個に同じ頂点由来のAv, Bvが両方含まれていたら上のように構成してしまえばよい
明らかにこれが最小値
含まれていないときは, 最初のn項についてそれぞれ取り除いたときにどうなるかを考える
Aw/Bwを取り除いたとすると, N+1番目の項がBw/AwでなければN+1番目の項を追加
Bw/Awの時はN+2番目の項を追加
（最初のN項が頂点について被りがないという条件から、これにより必ずあるvについてAv, Bv両方が含まれることになる
'''

n = int(input())
x = []
for i in range(n):
    ai, bi = map(int, input().split())
    x += [[i, ai, 0], [i, bi, 1]]
s1 = sum([x[2 * i][1] for i in range(n)])
s2 = sum([x[2 + i + 1][1] for i in range(n)])


x.sort(key = lambda x: x[1])
s3 = sum([x[i][1] for i in range(n)])
if len(set([x[i][0] for i in range(n)])) != n:
    print(min(s1, s2, s3))
else:
    if x[n - 1][0] == x[n][0]:
        s4 = min(s3 - x[n - 1][1] + x[n + 1][1], s3 - x[n - 2][1] + x[n][1])
    else:
        s4 = s3 - x[n - 1][1] + x[n][1]
    print(min(s1, s2, s4))

