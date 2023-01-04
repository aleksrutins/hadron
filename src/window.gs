/* window.vala
 *
 * Copyright 2023 Aleks Rutins
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */
[indent=4]

uses
    Gtk
    GLib

namespace Hadron
    [GtkTemplate (ui = "/com/rutins/Hadron/window.ui")]
    class Window : Gtk.ApplicationWindow
        [GtkChild]
        sourceview: unowned GtkSource.View

        construct(app: Application)
            Object (application: app);
