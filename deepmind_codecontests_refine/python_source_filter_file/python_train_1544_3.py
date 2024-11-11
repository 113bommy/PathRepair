#入力
n,x=map(int,input().split())
line=list(map(int,input().split()))
#累積和を計算しておく
#はじめに0を入れておくと、右からi番目で計算できる(i-1としなくて良い)
Sum=[0]
sum=0
#lineの後ろから値を取って、sumに足してlistに入れる
for i in range(n):
  sum+=line.pop()
  Sum.append(sum)
#大きい数で初期化(今回は小さい数の方が選ばれるので、十分大きい数で)
Ans=10**18
#それぞれのkについてコストを計算
for k in range(1,n):
  #pは純粋な移動のみのコスト
  p=0
  #kで割り切れる時は、n//k -1個のグループが出来る(最初は2kでグループを作る)
  #kで割り切れない時は、n//k 個のグループが出来る
  #よってn-1しておけばkで割り切れる時だけ-1出来る
  for i in range((n-1)//k):
    #はじめだけ処理が異なる
    if i==0:
      if n>=2k:
        p+= (Sum[k])*5
      #2kの長さがなければ最初から最後まで足して終わり
      else:
        p+=(Sum[n])*5
        break
    else:
      if n> (k*i +2*k):
        #(i+1)*k+1から(i+2)*kまでの座標の和に移動コストをかける
        p+= (Sum[k*i +2*k]-Sum[k*(i-1) +2*k])*(2*i +5)
      else:
        p+= (Sum[n]-Sum[k*(i-1) +2*k])*(2*i +5)
        break
  #n*xが1)のコスト、k*xが2)のコスト
  ans=(n+k)*x + p
  #小さい方をAnsに代入
  Ans=min(Ans,ans)
#答え
print(Ans)