t = int(input())
for _ in range(t):
  n, m = map(int, input().split())
  l = "vika"
  cur = 0
  arr = [input() for _ in range(n)]
  for i in range(m):
    s = ""
    for j in range(n):
      s += arr[j][i]
    if cur<4 and s.find(l[cur]) != -1:
      cur += 1
  if cur >= 4:
    print("YES")
  else:
    print("NO")
