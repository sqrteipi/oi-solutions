for test in range(1, 11):
    with open(f"stars{test}.txt") as file:
        n, v, t = map(int, file.readline().split())
        arr = [[int(x) for x in file.readline().split()] for _ in range(n)]

    grid = [[0 for _ in range(91)] for _ in range(91)]
    for p in arr:
        grid[p[0]+40][p[1]+40] = 1

    with open(f"stars{test}.vis", "w") as file:
        for i in range(91):
            for j in range(91):
                file.write(str(grid[i][j]))
            file.write("\n")