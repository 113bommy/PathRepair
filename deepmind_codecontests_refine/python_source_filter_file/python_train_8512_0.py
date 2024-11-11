from math import gcd

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

class Seg_min():
    def __init__(self,x):
        #####単位元######
        self.ide_ele_min = 10**10
        self.func = min

        self.n = len(x)

        #num_max:n以上の最小の2のべき乗
        self.num_max =2**(self.n-1).bit_length()
        self.x = [self.ide_ele_min]*2*self.num_max

        for i,num in enumerate(x, self.num_max):
            self.x[i] = num
        for i in range(self.num_max-1,0,-1):
            self.x[i] = self.func(self.x[i<<1],self.x[(i<<1) + 1])

    def update(self,i,x):
        i += self.num_max
        self.x[i] = x
        while(i>0):
            i = i//2
            self.x[i] = self.func(self.x[i<<1],self.x[(i<<1) + 1])

    def query(self,i,j):
        res = self.ide_ele_min
        if i>=j:
            return res
        i += self.num_max
        j += self.num_max -1
        while(i<=j):
            if(i==j):
                res = self.func(res,self.x[i])
                break
            if(i&1):
                res = self.func(res,self.x[i])
                i += 1
            if(not j&1):
                res = self.func(res,self.x[j])
                j -= 1
            i = i>>1
            j = j>>1
        return res


class Seg_max():
    def __init__(self,x):
        #####単位元######
        self.ide_ele_min = 10**10 * -1
        self.func = max

        self.n = len(x)

        #num_max:n以上の最小の2のべき乗
        self.num_max =2**(self.n-1).bit_length()
        self.x = [self.ide_ele_min]*2*self.num_max

        for i,num in enumerate(x, self.num_max):
            self.x[i] = num
        for i in range(self.num_max-1,0,-1):
            self.x[i] = self.func(self.x[i<<1],self.x[(i<<1) + 1])

    def update(self,i,x):
        i += self.num_max
        self.x[i] = x
        while(i>0):
            i = i//2
            self.x[i] = self.func(self.x[i<<1],self.x[(i<<1) + 1])

    def query(self,i,j):
        res = self.ide_ele_min
        if i>=j:
            return res
        i += self.num_max
        j += self.num_max -1
        while(i<=j):
            if(i==j):
                res = self.func(res,self.x[i])
                break
            if(i&1):
                res = self.func(res,self.x[i])
                i += 1
            if(not j&1):
                res = self.func(res,self.x[j])
                j -= 1
            i = i>>1
            j = j>>1
        return res

# aの最大値のindexを取得
max_ind = 0
max_num = -1
for ind,i in enumerate(a):
    if(i > max_num):
        max_ind = ind
        max_num = i

# max_ind が先頭になるように順番を変更
a = a[max_ind:] + a[:max_ind]
b = b[max_ind:] + b[:max_ind]

# Aiが小さい順に探索する。その順番を取得しておく。
order = [(i,ind) for ind,i in enumerate(a)]
order.sort()

# 累積和を作る。
# cs1は普通のBiの累積和
# cs2はi*Biの累積和
cs1_l = [0] * (n)
cs2_l = [0] * (n)
cs1_r = [0] * (n+1)
cs2_r = [0] * (n+1)

for i in range(1,n):
    cs1_l[i] = cs1_l[i-1] + b[i]
    cs2_l[i] = cs2_l[i-1] + b[i]*i

for i in range(1,n):
    cs1_r[-(i+1)] = cs1_r[-i] + b[-i]
    cs2_r[-(i+1)] = cs2_r[-i] + b[-i]*i

# 1週して戻ってくる点を追加しておく
a.append(a[0])
b.append(b[0])

# ゲームを終了する位置を記録・取得するためにセグ木を使う
seg_left = Seg_max( list(range(n+1)) )
seg_right = Seg_min( list(range(n+1)) )

# すべての点について、終了するかしないかを記録しておく。
end = [1] * (n+1)
# end[0] = 1
# end[-1] = 1

# 終了しない場合の期待値計算の関数
def calc_ex(ind):
    left = seg_left.query(0,ind)
    right = seg_right.query(ind+1,n+1)

    div = right - left
    wid_l = ind-left
    wid_r = right-ind
    # left-ind
    base = cs2_l[ind] - cs2_l[left] - (cs1_l[ind] - cs1_l[left])*left
    ex_l = base*2 * wid_r

    # ind-right
    base = cs2_r[ind] - cs2_r[right] - (cs1_r[ind] - cs1_r[right])*(n-right)
    ex_r = base*2 * wid_l

    ex = -ex_l - ex_r + b[ind]*wid_l*wid_r*2 + a[left]*wid_r + a[right]*wid_l

    return ex,div


# Aiが小さい順に期待値計算をして、終了するかどうか判断。
# A0は絶対に終了すべきなのでskip
order = [j for i,j in order][::-1]
flag = True
while(flag):
    flag = False
    while(order):
        ind = order.pop()
        if(ind==0):
            continue
        if(end[ind]==0):
            continue

        ex,div = calc_ex(ind)
        if(a[ind]*div < ex):
            end[ind] = 0
            seg_left.update(ind,0)
            seg_right.update(ind,n)

            left = seg_left.query(0,ind)
            right = seg_right.query(ind+1,n+1)
            if(left!=0):
                order.append(left)
            if(right!=0):
                order.append(right)
            flag = True

    if(flag):
        for i,val in enumerate(end[:-1]):
            if(val==1):
                order.append(i)

# 終了すべきポイントがわかったので期待値合計を計算
ans = [0] * (n)
for ind,flag in enumerate(end[:-1]):
    if(flag==1):
        ans[ind] = (a[ind],1)
    else:
        ex,div = calc_ex(ind)
        ans[ind] = (ex,div)

lcm = 1
for ex,div in ans:
    lcm = (lcm*div)//gcd(lcm,div)

ans_num = 0
for ex,div in ans:
    ans_num += ex*(lcm//div)

print(ans_num/(lcm*n))