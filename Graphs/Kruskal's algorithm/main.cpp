/*
MST-Kruskal(G, w)
1. A <- NULL;
2. For each vertex v  IN G.V
  3. MAKE-SET(v)
4. sort the edges of G.E in nondecreasingorder of weight
5. for each edge (u, v) IN G.E, in order of nondecreasing weight
  6.if FIND-SET(u)  INEQUAL FIND-SET (v)
    7. A <- A U {(u,v)}
    8. UNION(u,v)
9. return A
*/
