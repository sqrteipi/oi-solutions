var n, i, j, t, r : longint;
    coeff : array[0..1000] of longint;
	diag_plus, diag_minus : array[0..1999] of longint;
	used : array[0..999] of boolean;
	a : array[0..999] of longint;
	ok_moves_num : longint;
	ok_moves_i, ok_moves_j : array[1..1000000] of longint;
	better_found : boolean;
	dplus, dminus, conflicts, new_conflicts : longint;

begin
  readln(n);
  for i := 0 to n do
    coeff[i] := i*(i-1) div 2;
	
  filldword(diag_plus, n+n, 0);
  filldword(diag_minus, n+n, 0);

  fillchar(used, n, 0);
  r := -1;
  for i := 0 to n-1 do begin
    r := (r+2) mod n;
    if used[r] then dec(r);
	used[r] := true;
	a[i] := r;
    inc(diag_plus[i+a[i]]);
    inc(diag_minus[a[i]-i+n]);
  end;
  conflicts := 0;
  for i := 0 to n+n-1 do
    conflicts := conflicts + coeff[diag_plus[i]] + coeff[diag_minus[i]];

  while conflicts > 0 do begin
    
    better_found := false;
    ok_moves_num := 0;

    for i := 0 to n-1 do
        for j := i+1 to n-1 do begin
            new_conflicts := conflicts;
            
            dplus := diag_plus[i+a[i]];
			dminus := diag_minus[a[i]-i+n];
            new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
            dec(diag_plus[i+a[i]]);
            dec(diag_minus[a[i]-i+n]);
            new_conflicts := new_conflicts + coeff[dplus-1] + coeff[dminus-1];

            dplus := diag_plus[j+a[j]];
			dminus := diag_minus[a[j]-j+n];
            new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
            dec(diag_plus[j+a[j]]);
            dec(diag_minus[a[j]-j+n]);
            new_conflicts := new_conflicts + coeff[dplus-1] + coeff[dminus-1];
			
            t := a[i]; a[i] := a[j]; a[j] := t;

            dplus := diag_plus[i+a[i]];
			dminus := diag_minus[a[i]-i+n];
            new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
            inc(diag_plus[i+a[i]]);
            inc(diag_minus[a[i]-i+n]);
            new_conflicts := new_conflicts + coeff[dplus+1] + coeff[dminus+1];

            dplus := diag_plus[j+a[j]];
			dminus := diag_minus[a[j]-j+n];
            new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
            inc(diag_plus[j+a[j]]);
            inc(diag_minus[a[j]-j+n]);
            new_conflicts := new_conflicts + coeff[dplus+1] + coeff[dminus+1];

            if new_conflicts < conflicts then begin
                conflicts := new_conflicts;
                better_found := true;
                continue;
			end
			else if new_conflicts = conflicts then begin
				inc(ok_moves_num);
                ok_moves_i[ok_moves_num] := i;
				ok_moves_j[ok_moves_num] := j;
			end;

            dec(diag_plus[i+a[i]]);
            dec(diag_minus[a[i]-i+n]);

            dec(diag_plus[j+a[j]]);
            dec(diag_minus[a[j]-j+n]);

            t := a[i]; a[i] := a[j]; a[j] := t;

            inc(diag_plus[i+a[i]]);
            inc(diag_minus[a[i]-i+n]);

            inc(diag_plus[j+a[j]]);
            inc(diag_minus[a[j]-j+n]);
		end;

    if not better_found then
		if ok_moves_num = 0 then begin
		  (* random restart *)
		  fillchar(used, n, 0);
		  for i := 0 to n-1 do begin
			repeat
				r := random(n);
			until not used[r];
			used[r] := true;
			a[i] := r;
			inc(diag_plus[i+a[i]]);
			inc(diag_minus[a[i]-i+n]);
		  end;
		  conflicts := 0;
		  for i := 0 to n+n-1 do
			conflicts := conflicts + coeff[diag_plus[i]] + coeff[diag_minus[i]];
			
		end
		else begin
			new_conflicts := conflicts;
			
			r := random(ok_moves_num)+1;

			i := ok_moves_i[r];
			j := ok_moves_j[r];
			
			dplus := diag_plus[i+a[i]];
			dminus := diag_minus[a[i]-i+n];
			new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
			dec(diag_plus[i+a[i]]);
			dec(diag_minus[a[i]-i+n]);
			new_conflicts := new_conflicts + coeff[dplus-1] + coeff[dminus-1];

			dplus := diag_plus[j+a[j]];
			dminus := diag_minus[a[j]-j+n];
			new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
			dec(diag_plus[j+a[j]]);
			dec(diag_minus[a[j]-j+n]);
			new_conflicts := new_conflicts + coeff[dplus-1] + coeff[dminus-1];
			
			t := a[i]; a[i] := a[j]; a[j] := t;

			dplus := diag_plus[i+a[i]];
			dminus := diag_minus[a[i]-i+n];
			new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
			inc(diag_plus[i+a[i]]);
			inc(diag_minus[a[i]-i+n]);
			new_conflicts := new_conflicts + coeff[dplus+1] + coeff[dminus+1];

			dplus := diag_plus[j+a[j]];
			dminus := diag_minus[a[j]-j+n];
			new_conflicts := new_conflicts - coeff[dplus] - coeff[dminus];
			inc(diag_plus[j+a[j]]);
			inc(diag_minus[a[j]-j+n]);
			new_conflicts := new_conflicts + coeff[dplus+1] + coeff[dminus+1];

			conflicts := new_conflicts;
		end;
  end;   

  for i := 0 to n-1 do
    writeln(i+1,' ',a[i]+1);
end.
