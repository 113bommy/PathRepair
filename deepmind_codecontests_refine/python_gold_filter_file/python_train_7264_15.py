# -*- coding: utf-8 -*-
"""
Created on Sun Apr 19 15:35:41 2020

@author: ybt07
"""

class SegmentTreeMax():
    def __init__(self,n,init):
        # n = 7 のとき
        # offset = 2 ** 3 = 8
        # 実際のデータは tree[0+8], tree[1+8],,,, に入る
        # tree[0～8] は区間の値を入れるために使われている
        self.offset = 2 ** ((n-1).bit_length())  # セグメント木を配列で行玄する際のオフセット量
        self.tree = [init] * (2 * self.offset)
        self.init = init

    def update(self, pos, val): # pos番目の要素を覆う要素すべてについて値を更新する
        pos += self.offset
        self.tree[pos] = val  # n=7, pos=5 のとき tree[5+8] に val が入る
        while pos > 1:
            pos = pos // 2  # 13 // 2 = 6
            # tree[6] に tree[12],tree[13] の大きい方が入る
            self.tree[pos] = max(self.tree[2 * pos],self.tree[2 * pos + 1])

    def query(self, left, right): # 区間[l,r]での最大値を求める
        # 例のごとく、オフセット
        left += self.offset
        right += self.offset
        ret = self.init  # 再帰的に書くので、初期値を設定
        while left <= right:
            ret = max(ret, self.tree[right])
            right = (right - 1) // 2
            ret = max(ret, self.tree[left])
            left = (left + 1) // 2
        return ret

mod=998244353
n=int(input())
xd = [list(map(int,input().split())) for _ in range(n)]
xd = sorted(xd,key=lambda x:x[0]) #X座標の小さい順にソートする

st = SegmentTreeMax(n,0)
ranges = []

for i in range(n):
    r = xd[i][0] + xd[i][1] #各ロボットが到達できる最大の位置
    left = -1
    right = n
    
    #2分探索によりどのロボットまで影響するかを求める(0-indexed)
    while right - left != 1:  # right と left の間が 1 （隣り合う） 行う
        mid = (left + right) // 2
        if xd[mid][0] >= r:  # index 上で中間の要素に届くか？
            right = mid  # ぶつからないところにいれば、もっと左を探す（さがす範囲を更新）

        else:
            left = mid  # ぶつかるところにいれば、もっと右を探す（さがす範囲を更新）
            
    ranges.append(right - 1)  # i 番目のロボットが right - 1 番目のロボットまで影響することを記録する
    st.update(i, right - 1) # セグメント木のi番目の要素を right - 1に更新する

for i in range(n-1,-1,-1):
    # x の大きい側から求めていくことで、玉突きでどこまで影響するか？の数字が求められる
    # j番目 = ranges[i] が影響する 範囲が、既にrange[j] に入っている
    ranges[i] = st.query(i,ranges[i]) # 区間[i,k]での番号の最大値を求める
    st.update(i, ranges[i]) # セグメント木のi番目の要素を上記の最大値に更新する

dp = [0] * (n+1)
dp[-1] = 1 #DPの初期値は1(すべてのロボットを除いた場合に相当する)

for i in range(n-1,-1,-1):
    j = ranges[i] + 1  # j : i の動作が影響を及ぼさない、右側にある、最小の j
    dp[i] = dp[i+1] + dp[j] #後ろから順にDP[i]=DP[i+1]+DP[j]として更新する
    dp[i] %= mod

print(dp[0])