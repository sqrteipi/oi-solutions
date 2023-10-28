t = int(input())
for _ in range(t):
  a, b = input().split()
  if len(a) > len(b):
    a, b = b, a
  a = list(a)
  b = list(b)
  a = sorted(a)
  b = sorted(b, reverse=True)
  cnt = 0
  for i in range(len(b)):
    if i + len(a) < len(b):
      j = 0
    else:
      j = a[-i+1]
    cnt += abs(int(b[i])-int(j))
  print(cnt)
