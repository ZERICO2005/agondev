	.assume	adl=1

	.section	.text

;-------------------------------------------------------------------------------

	.global	_crt_bdivu
_crt_bdivu:
	ld	iy, 0
	add	iy, sp
	ld	b, (iy + 3)
	ld	c, (iy + 6)
	jp	__bdivu
	.extern	__bdivu

	.global	_crt_bdivs
_crt_bdivs:
	ld	iy, 0
	add	iy, sp
	ld	b, (iy + 3)
	ld	c, (iy + 6)
	jp	__bdivs
	.extern	__bdivs

	.global	_crt_bremu
_crt_bremu:
	ld	iy, 0
	add	iy, sp
	ld	a, (iy + 3)
	ld	c, (iy + 6)
	jp	__bremu
	.extern	__bremu

	.global	_crt_brems
_crt_brems:
	ld	iy, 0
	add	iy, sp
	ld	a, (iy + 3)
	ld	c, (iy + 6)
	jp	__brems
	.extern	__brems

;-------------------------------------------------------------------------------

	.global	_crt_sdivu
_crt_sdivu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__sdivu
	.extern	__sdivu

	.global	_crt_sdivs
_crt_sdivs:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__sdivs
	.extern	__sdivs

	.global	_crt_sremu
_crt_sremu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__sremu
	.extern	__sremu

	.global	_crt_srems
_crt_srems:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__srems
	.extern	__srems

;-------------------------------------------------------------------------------

	.global	_crt_idivu
_crt_idivu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__idivu
	.extern	__idivu

	.global	_crt_idivs
_crt_idivs:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__idivs
	.extern	__idivs

	.global	_crt_iremu
_crt_iremu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__iremu
	.extern	__iremu

	.global	_crt_irems
_crt_irems:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	bc, (iy + 6)
	jp	__irems
	.extern	__irems

;-------------------------------------------------------------------------------

	.global	_crt_ldivu
_crt_ldivu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	e, (iy + 6)
	ld	bc, (iy + 9)
	ld	a, (iy + 12)
	jp	__ldivu
	.extern	__ldivu

	.global	_crt_ldivs
_crt_ldivs:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	e, (iy + 6)
	ld	bc, (iy + 9)
	ld	a, (iy + 12)
	jp	__ldivs
	.extern	__ldivs

	.global	_crt_lremu
_crt_lremu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	e, (iy + 6)
	ld	bc, (iy + 9)
	ld	a, (iy + 12)
	jp	__lremu
	.extern	__lremu

	.global	_crt_lrems
_crt_lrems:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	e, (iy + 6)
	ld	bc, (iy + 9)
	ld	a, (iy + 12)
	jp	__lrems
	.extern	__lrems

;-------------------------------------------------------------------------------

	.global	_i_crt48divu
_crt_i48divu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	de, (iy + 6)
	ld	bc, (iy + 9)
	ld	iy, (iy + 12)
	jp	__i48divu
	.extern	__i48divu

	.global	_i_crt48divs
_crt_i48divs:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	de, (iy + 6)
	ld	bc, (iy + 9)
	ld	iy, (iy + 12)
	jp	__i48divs
	.extern	__i48divs

	.global	_i_crt48remu
_crt_i48remu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	de, (iy + 6)
	ld	bc, (iy + 9)
	ld	iy, (iy + 12)
	jp	__i48remu
	.extern	__i48remu

	.global	_i_crt48rems
_crt_i48rems:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 3)
	ld	de, (iy + 6)
	ld	bc, (iy + 9)
	ld	iy, (iy + 12)
	jp	__i48rems
	.extern	__i48rems

;-------------------------------------------------------------------------------

	.global	__crtlldivu
_crt_lldivu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 18)
	push	hl
	ld	hl, (iy + 15)
	push	hl
	ld	hl, (iy + 12)
	push	hl
	ld	bc, (iy + 9)
	ld	de, (iy + 6)
	ld	hl, (iy + 3)
	call	__lldivu
	ld	sp, iy
	ret
	.extern	__lldivu

	.global	__crtlldivs
_crt_lldivs:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 18)
	push	hl
	ld	hl, (iy + 15)
	push	hl
	ld	hl, (iy + 12)
	push	hl
	ld	bc, (iy + 9)
	ld	de, (iy + 6)
	ld	hl, (iy + 3)
	call	__lldivs
	ld	sp, iy
	ret
	.extern	__lldivs

	.global	__crtllremu
_crt_llremu:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 18)
	push	hl
	ld	hl, (iy + 15)
	push	hl
	ld	hl, (iy + 12)
	push	hl
	ld	bc, (iy + 9)
	ld	de, (iy + 6)
	ld	hl, (iy + 3)
	call	__llremu
	ld	sp, iy
	ret
	.extern	__llremu

	.global	__crtllrems
_crt_llrems:
	ld	iy, 0
	add	iy, sp
	ld	hl, (iy + 18)
	push	hl
	ld	hl, (iy + 15)
	push	hl
	ld	hl, (iy + 12)
	push	hl
	ld	bc, (iy + 9)
	ld	de, (iy + 6)
	ld	hl, (iy + 3)
	call	__llrems
	ld	sp, iy
	ret
	.extern	__llrems

;-------------------------------------------------------------------------------
