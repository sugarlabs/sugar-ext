/*
 * Copyright (C) 2014, Martin Abente Lahaye - tch@sugarlabs.org
 * Copyright (C) 2025, Chihurumnaya Ibiam   - ibiam@sugarlabs.org
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "sugar-clipboard.h"

/**
 * sugar_clipboard_set_with_data:
 * @clipboard: a #GdkClipboard
 * @mime_type: mime type.
 * @user_data: user data to pass.
 *
 * Sets a new content provider on clipboard.
 *
 * Return value: %TRUE if setting the clipboard data succeeded.
**/

gboolean
sugar_clipboard_set_with_data (GdkClipboard *clipboard,
                               const gchar  *mime_type,
                               gpointer      user_data)
{
    GBytes *data = g_bytes_new_take (user_data, sizeof(user_data));
    GdkContentProvider *provider = gdk_content_provider_new_for_bytes (mime_type, data);

    return gdk_clipboard_set_content (clipboard,
				      provider);
}
