/* SPDX-License-Identifier: BSD-2-Clause-Patent */

SECTIONS
{
  _text = .;
} INSERT BEFORE .text;

SECTIONS
{
  _DYNAMIC = .;
} INSERT BEFORE .dynamic;

/* vim:filetype=ld:fenc=utf-8:tw=80:et:sts=2:sw=2
 */
