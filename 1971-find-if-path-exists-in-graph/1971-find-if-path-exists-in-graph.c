bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int src, int dest) {
    if (src == dest)
        return (true);

    char    *links = calloc(n, sizeof(bool));
    links[src] = 1;

    char    expand = true;
    while (expand) {
        expand = false;
        for (int i = 0; i < edgesSize; i++) {
            if ((links[edges[i][0]] && edges[i][1] == dest) || (links[edges[i][1]] && edges[i][0] == dest))
                return (true);
            if (links[edges[i][0]] && !links[edges[i][1]]) {
				expand = true;
				links[edges[i][1]] = 1;
			}
			if (links[edges[i][1]] && !links[edges[i][0]]) {
				expand = true;
				links[edges[i][0]] = 1;
			}
        }
    }
    return (false);
}