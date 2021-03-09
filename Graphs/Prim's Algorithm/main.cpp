/*
MST-Prim(G, w, r)
1. for each vertex u  IN G.V
  2. u.key= INF
  3. u.pi= NIL
4. r.key= 0
5. Q= G.V
6. while Q INEQUAL NULL
  7. u= EXTRACT-MIN(Q)
  8. for each v  IN G.Adj[u]
    9. if v in Q and w(u, v) < v.key
      10. v.pi= u
      11.v.key=w(u,v)
*/
