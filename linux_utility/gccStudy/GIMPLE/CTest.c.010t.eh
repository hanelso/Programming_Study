
;; Function main (main, funcdef_no=0, decl_uid=2247, cgraph_uid=0, symbol_order=0)

main ()
{
  int k;
  int j;
  int i;
  int D.2259;

  j = 0;
  k = 0;
  i = 0;
  goto <D.2253>;
  <D.2252>:
  i.0_1 = (unsigned int) i;
  _2 = i.0_1 & 1;
  if (_2 != 0) goto <D.2256>; else goto <D.2257>;
  <D.2256>:
  j = j + 1;
  goto <D.2258>;
  <D.2257>:
  k = k + 1;
  <D.2258>:
  printf ("j = %d, k = %d\n", j, k);
  i = i + 1;
  <D.2253>:
  if (i <= 9) goto <D.2252>; else goto <D.2254>;
  <D.2254>:
  D.2259 = 0;
  goto <D.2260>;
  D.2259 = 0;
  goto <D.2260>;
  <D.2260>:
  return D.2259;
}


