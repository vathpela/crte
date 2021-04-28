/* SPDX-License-Identifier: BSD-2-Clause-Patent */

SECTIONS
{
  _text = .;
} INSERT BEFORE .text;

SECTIONS
{
  _DYNAMIC = .;
} INSERT BEFORE .dynamic;

SECTIONS
{
  /*
   * XXX FIXME
   *
   * Note that these aren't the using the GNU "CONSTRUCTOR" output section
   * command, so they don't start with a size.  Because of p2align and the
   * end/END definitions, and the fact that they're mergeable, they can also
   * have NULLs which aren't guaranteed to be at the end.
   */
  . = ALIGN(4096);
  .ctors :
  {
    _init_array = .;
    *(SORT_BY_NAME(.init_array))
    _init_array_end = .;
    __CTOR_LIST__ = .;
    *(SORT_BY_NAME(.ctors))
    __CTOR_END__ = .;
    . = ALIGN(4096);
  } =0x00000000

  . = ALIGN(4096);
  .dtors :
  {
    __DTOR_LIST__ = .;
    *(SORT_BY_NAME(.dtors))
    __DTOR_END__ = .;
    _fini_array = .;
    *(SORT_BY_NAME(.fini_array))
    _fini_array_end = .;
    . = ALIGN(4096);
  } =0x00000000
}
INSERT AFTER .text;

/* vim:filetype=ld:fenc=utf-8:tw=80:et:sts=2:sw=2
 */
