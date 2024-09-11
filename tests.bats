test_dir=tests
prog=motscaches

@test "Test 0 : Aucun argument" {
	run ./$prog
	[ "$status" -eq 1 ]
	[ "${lines[0]}" = "Erreur, nombre d'arguments invalide." ]
}

@test "Test 1 : 2 arguments" {
	run ./$prog mandoline.txt dummy.txt
	[ "$status" -eq 1 ]
	[ "${lines[0]}" = "Erreur, nombre d'arguments invalide." ]
}

@test "Test 2 : fichier invalide" {
	run ./$prog dummy.txt
	[ "$status" -eq 1 ]
	[ "${lines[0]}" = "Erreur, échec de lecture du fichier." ]
}

@test "Test 3 : réponse = MANDOLINE" {
	run ./$prog ./$test_dir/mandoline.txt
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "MANDOLINE" ]
}

